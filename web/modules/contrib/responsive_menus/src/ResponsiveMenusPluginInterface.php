<?php

namespace Drupal\responsive_menus;

use Drupal\Component\Plugin\ConfigurableInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 * Interface ResponsiveMenusInterface.
 *
 * @package Drupal\responsive_menus
 */
interface ResponsiveMenusPluginInterface extends ConfigurableInterface {

  /**
   * Provide UI with plugins selector information.
   */
  public static function getSelectorInfo();

  /**
   * Form constructor.
   *
   * @param array $form
   *   An associative array containing the initial structure of the plugin form.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The current state of the complete form.
   *
   * @return array
   *   The form structure.
   */
  public function settingsForm(array $form, FormStateInterface $form_state);

  /**
   * Get Drupal Javscript settings array.
   *
   * @return array
   *   The Javascript settings array.
   */
  public function getJsSettings();

}
