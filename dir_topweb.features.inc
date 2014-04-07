<?php
/**
 * @file
 * dir_topweb.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function dir_topweb_eck_bundle_info() {
  $items = array(
    'dir_rank_alexa' => array(
      'machine_name' => 'dir_rank_alexa',
      'entity_type' => 'dir_rank',
      'name' => 'alexa',
      'label' => 'Alexa',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function dir_topweb_eck_entity_type_info() {
  $items = array(
    'dir_rank' => array(
      'name' => 'dir_rank',
      'label' => 'Dir: Rank',
      'properties' => array(
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'link' => array(
          'label' => 'Link',
          'type' => 'positive_integer',
          'behavior' => 'entityreference',
        ),
      ),
    ),
  );
  return $items;
}
