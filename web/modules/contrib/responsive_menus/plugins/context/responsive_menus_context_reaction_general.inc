<?php

use Drupal\context\ContextReactionPluginBase;

/**
 * Exposes Responsive Menus as a reaction in Context.
 *
 * @ContextReaction(
 *   id = "responsive_menus",
 *   label = @Translation("Responsive Menus")
 * )
 */
class ResponsiveMenusContextReactionGeneral extends ContextReactionPluginBase {
  /**
   * Configure the responsive menu settings.
   */
  /*function options_form($context) {
  $values = $this->fetch_from_context($context);
  $form_state = (empty($form_state) ? array() : $form_state);
  if (empty($form_state['build_info']['args'])) {
  $form_state['build_info']['args'] = array();
  }
  if (!empty($values)) {
  $form_state['values'] = $values;
  }
  module_load_include('inc', 'responsive_menus',
  'includes/context/responsive_menus_context');
  $form = drupal_retrieve_form('responsive_menus_context_options_form'
  , $form_state);

  return $form;
  }*/

  /**
   * Execute & make those menus responsive.
   */
  public function execute() {
    // $contexts = context_active_contexts();
    $contextManager = \Drupal::service('context.manager');
    $contexts = $contextManager->getActiveContexts();

    foreach ($contexts as $value) {
      if (!empty($value->reactions[$this->plugin])) {
        $style = $value->reactions[$this->plugin]['responsive_menus_style'];
        $js_defaults = $value->reactions[$this->plugin]['responsive_menus_style_settings'];
        // Execute the responsiveness!
        responsive_menus_execute($style, $js_defaults);
      }
    }
  }

}
